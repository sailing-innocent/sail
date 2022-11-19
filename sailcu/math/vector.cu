#include <sailcu/vector.h>

__global__ void dVectorAdd(double* vec_a, double* vec_b, double* vec_c, size_t _size)
{
    int tid = blockIdx.x;
    if (tid < _size) {
        vec_c[tid] = vec_a[tid] + vec_b[tid];
    }
}

SAIL_NAMESPACE_BEGIN

Vector4dCu Vector4dCu::operator+(const Vector4dCu& rhs)
{
    double a[4],b[4];
    double res[4];
    double *dev_a, *dev_b, *dev_c;
    cudaMalloc((void**)&dev_a, 4 * sizeof(double));
    cudaMalloc((void**)&dev_b, 4 * sizeof(double));
    cudaMalloc((void**)&dev_c, 4 * sizeof(double));
    for (auto i = 0; i < 4; i++) {
        a[i] = this->mData[i];
        b[i] = rhs[i];
    }
    cudaMemcpy(dev_a, a, 4 * sizeof(double), cudaMemcpyHostToDevice);
    cudaMemcpy(dev_b, b, 4 * sizeof(double), cudaMemcpyHostToDevice);

    dVectorAdd<<<4,1>>>(dev_a, dev_b, dev_c, 4);
    cudaMemcpy(res, dev_c, 4 * sizeof(double), cudaMemcpyDeviceToHost);

    cudaFree(dev_a);
    cudaFree(dev_b);
    cudaFree(dev_c);
    return Vector4dCu(res);
}

SAIL_NAMESPACE_END