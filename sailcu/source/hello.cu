#include <sailcu/hello.h>

__global__ void add(int *a, int *b, int *c)
{
    int tid = blockIdx.x;
    if (tid < N) {
        for (auto j = 0; j < N; j++) {
            a[tid] = a[tid] + j;
            b[tid] = b[tid] + j * j;
        }
        c[tid] = a[tid] + b[tid];
    }
}

SAIL_NAMESPACE_BEGIN

void printHello()
{
    // std::cout << "Hello you" << std::endl;
    int a[N], b[N], c[N];
    int *dev_a, *dev_b, *dev_c;

    cudaMalloc((void**)&dev_a, N * sizeof(int));
    cudaMalloc((void**)&dev_b, N * sizeof(int));
    cudaMalloc((void**)&dev_c, N * sizeof(int));

    for (int i = 0; i < N; i++) {
        a[i] = -i;
        b[i] = i * i;
    }

    cudaMemcpy(dev_a, a, N * sizeof(int), cudaMemcpyHostToDevice);
    cudaMemcpy(dev_b, b, N * sizeof(int), cudaMemcpyHostToDevice);

    add<<<N, 1>>>(dev_a, dev_b, dev_c);

    cudaMemcpy(c, dev_c, N * sizeof(int), cudaMemcpyDeviceToHost);

    for (int i = 0; i < N; i++) {
        // printf("%d + %d = %d \n", a[i], b[i], c[i]);
    }

    cudaFree(dev_a);
    cudaFree(dev_b);
    cudaFree(dev_c);
}

SAIL_NAMESPACE_END
