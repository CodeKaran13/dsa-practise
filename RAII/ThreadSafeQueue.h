//
// Copyright (c) 2026 CodeKaranGames.
// This source code is the property of CodeKaranGames.
// Unauthorized copying, modification, distribution, or use is prohibited.
//

#ifndef DSA_PRATISE_THREADSAFEQUEUE_H
#define DSA_PRATISE_THREADSAFEQUEUE_H

#include <queue>
#include <mutex>
#include <condition_variable>
#include <optional>
#include <utility>

template <typename T>
class ThreadSafeQueue
{
private:
    std::queue<T> m_queue;
    mutable std::mutex m_mutex;
    std::condition_variable m_cv;

public:
    ThreadSafeQueue() = default;

    // delete copy constructor and copy assignment operator
    ThreadSafeQueue(const ThreadSafeQueue&) = delete;
    ThreadSafeQueue& operator=(const ThreadSafeQueue&) = delete;

    void Push(T value)
    {
        {
            std::lock_guard<std::mutex> lock(m_mutex);
            m_queue.push(value);
        }
        m_cv.notify_one();
    }

    T WaitAndPop()
    {
        std::unique_lock<std::mutex> lock(m_mutex);
        m_cv.wait(lock, [this]()
        {
            return !m_queue.empty();
        });

        T value = std::move(m_queue.front());
        m_queue.pop();
        return value;
    }

    std::optional<T> TryPop()
    {
        std::lock_guard<std::mutex> lock(m_mutex);
        if (m_queue.empty())
            return std::nullopt;

        T value = std::move(m_queue.front());
        m_queue.pop();

        return value;
    }

    bool Empty() const
    {
        std::lock_guard<std::mutex> lock(m_mutex);
        return m_queue.empty();
    }

    size_t Size() const
    {
        std::lock_guard<std::mutex> lock(m_mutex);
        return m_queue.size();
    }
};


#endif //DSA_PRATISE_THREADSAFEQUEUE_H
