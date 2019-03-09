## Sample

    #include <mmath/mmath.h>

    int main()
    {
        // 3D Vector with float, same as mmath::Vector<3, float>
        mmath::Vector3F v3f(1.5, 2.5, 3.5);
        // 3D Vector with int32_t, same as mmath::Vector<3, int32_t>
        mmath::Vector3L v3l(1, 2, 3);

        v3f *= v3l; // dot product
        v3l += v3f; // add 

        printf("v3f(%f, %f, %f)\n", v3f[0], v3f[1], v3f[2]); // v3f(1.500000, 5.000000, 10.500000)
        printf("v3l(%d, %d, %d)\n", v3l[0], v3l[1], v3l[2]); // v3l(2, 7, 13)
    }
