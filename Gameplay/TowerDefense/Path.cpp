//
// Created by Karan Nandkar on 02/06/26.
//

#include "Path.h"

namespace TowerDefense
{
    void Path::AddWaypoint(const Vector2& point)
    {
        waypoints.push_back(point);
    }

    const Vector2& Path::GetWaypoint(int index) const
    {
        return waypoints[index];
    }

    int Path::GetWaypointCount() const
    {
        return static_cast<int>(waypoints.size());
    }
} // TowerDefense
