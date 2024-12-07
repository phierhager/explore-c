#include <iostream>
#include <cuda_runtime.h>

__global__ void vectorAdd(int* A, int* B, int* C, int N) {
    int idx = threadIdx.x + blockIdx.x * blockDim.x;  // Global thread index
    if (idx < N) {  // Ensure we do not access out of bounds
        C[idx] = A[idx] + B[idx];  // Perform element-wise addition
    }
}

int main() {
    const int N = 1 << 20;  // Size of vectors
    size_t size = N * sizeof(int);

    // Allocate memory on the host
    int *h_A = new int[N];
    int *h_B = new int[N];
    int *h_C = new int[N];

    // Initialize vectors
    for (int i = 0; i < N; i++) {
        h_A[i] = i;
        h_B[i] = i;
    }

    // Allocate memory on the device
    int *d_A, *d_B, *d_C;
    cudaMalloc(&d_A, size);
    cudaMalloc(&d_B, size);
    cudaMalloc(&d_C, size);

    // Copy data from host to device
    cudaMemcpy(d_A, h_A, size, cudaMemcpyHostToDevice);
    cudaMemcpy(d_B, h_B, size, cudaMemcpyHostToDevice);

    // Launch the kernel
    dim3 dimGrid((N + 255) / 256);  // Number of blocks in the grid (rounded up to cover N elements)
    dim3 dimBlock(256);              // Number of threads per block (256 threads per block)
    vectorAdd<<<dimGrid, dimBlock>>>(d_A, d_B, d_C, N);

    // Copy result from device to host
    cudaMemcpy(h_C, d_C, size, cudaMemcpyDeviceToHost);

    // Verify the result
    for (int i = 0; i < N; i++) {
        if (h_C[i] != h_A[i] + h_B[i]) {
            std::cout << "Error at index " << i << ": " << h_C[i] << std::endl;
            return -1;
        }
    }

    std::cout << "Vector addition completed successfully!" << std::endl;

    // Free memory
    delete[] h_A;
    delete[] h_B;
    delete[] h_C;
    cudaFree(d_A);
    cudaFree(d_B);
    cudaFree(d_C);

    return 0;
}
