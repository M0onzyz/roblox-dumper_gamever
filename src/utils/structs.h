#pragma once
#include <cmath>

struct RGB {
    float r;
    float g;
    float b;
};

struct Vector3 {
    float x, y, z;

    bool equals(const Vector3& other, float epsilon = 0.01f) const {
        return std::abs(x - other.x) < epsilon && std::abs(y - other.y) < epsilon &&
               std::abs(z - other.z) < epsilon;
    }
};

struct Vector2 {
    float x, y;

    bool equals(const Vector2& other, float epsilon = 0.01f) const {
        return std::abs(x - other.x) < epsilon && std::abs(y - other.y) < epsilon;
    }

    bool operator==(const Vector2& other) const { return equals(other, 10.0f); }
};

struct UDim {
    float Scale;
    int Offset;

    bool equals(const UDim& other, float epsilon = 0.01f) const {
        return std::abs(Scale - other.Scale) < epsilon && Offset == other.Offset;
    }

    bool operator==(const UDim& other) const { return equals(other); }
};

struct UDim2 {
    UDim X;
    UDim Y;

    bool equals(const UDim2& other, float epsilon = 0.01f) const {
        return X.equals(other.X, epsilon) && Y.equals(other.Y, epsilon);
    }

    bool operator==(const UDim2& other) const { return equals(other); }
};
