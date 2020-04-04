#pragma once

#include "Vec2.h"
#include "Vec3.h"

Vec3 cross(const Vec3& vec_0, const Vec3& vec_1);
Vec3 dot(const Vec3& vec_0, const Vec3& vec_1);
float cross(const Vec2& vec_0, const Vec2& vec_1);
Vec2 dot(const Vec2& vec_0, const Vec2& vec_1);
Vec3 normalise(const Vec3& vec);
Vec2 normalise(const Vec2& vec);
float length(const Vec3& vec);
float length(const Vec2& vec);