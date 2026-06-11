//
// Created by Karan Nandkar on 02/06/26.
//

#ifndef DSA_PRATISE_PATH_H
#define DSA_PRATISE_PATH_H

#include <vector>
#include "../Gameplay/Vector.h"

namespace TowerDefense
{
    class Path
    {
    private:
        std::vector<Vector2> waypoints;

    public:
        void AddWaypoint(const Vector2& point);
        const Vector2& GetWaypoint(int index) const;
        int GetWaypointCount() const;
    };
} // TowerDefense

#endif //DSA_PRATISE_PATH_H
