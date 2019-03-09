## Sample

    #include <mmath/mmath.h>

    int main()
    {
        mmath::Vector3F v1(M_PI / 2, 0.0, 0.0);
        mmath::Vector3F v2(0.0, 0.0, 0.0);
        mmath::Quat q1;
        mmath::Quat q2;
        q1.FromEulerXYZ(v1);
        q2.FromEulerXYZ(v2);

        printf("q1.Angle(q2) = %f", q1.Angle(q2)); // q1.Angle(q2) = 1.570796
    }
