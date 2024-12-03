#include <stdlib.h>
#include <unistd.h>
int main( void )
{
    char* arr  = malloc(10);
    int*  arr2 = malloc(sizeof(int));
    write( 1 /* stdout */, arr, 10 );
    exit(arr2[0]);
}

// ==163946== Memcheck, a memory error detector
// ==163946== Copyright (C) 2002-2024, and GNU GPL'd, by Julian Seward et al.
// ==163946== Using Valgrind-3.24.0 and LibVEX; rerun with -h for copyright info
// ==163946== Command: ./a.out
// ==163946== 
// ==163946== Syscall param write(buf) points to uninitialised byte(s)
// ==163946==    at 0x498A574: write (write.c:26)
// ==163946==    by 0x1091C6: main (in /home/philip-hierhager/Programming/explore-c/valgrind/a.out)
// ==163946==  Address 0x4a83040 is 0 bytes inside a block of size 10 alloc'd
// ==163946==    at 0x484680F: malloc (vg_replace_malloc.c:446)
// ==163946==    by 0x10919E: main (in /home/philip-hierhager/Programming/explore-c/valgrind/a.out)
// ==163946== 
// ==163946== Syscall param exit_group(status) contains uninitialised byte(s)
// ==163946==    at 0x495C21D: _Exit (_exit.c:30)
// ==163946==    by 0x48B5A25: __run_exit_handlers (exit.c:131)
// ==163946==    by 0x48B5BAD: exit (exit.c:138)
// ==163946==    by 0x1091D3: main (in /home/philip-hierhager/Programming/explore-c/valgrind/a.out)
// ==163946== 
// ==163946== 
// ==163946== HEAP SUMMARY:
// ==163946==     in use at exit: 14 bytes in 2 blocks
// ==163946==   total heap usage: 2 allocs, 0 frees, 14 bytes allocated
// ==163946== 
// ==163946== LEAK SUMMARY:
// ==163946==    definitely lost: 0 bytes in 0 blocks
// ==163946==    indirectly lost: 0 bytes in 0 blocks
// ==163946==      possibly lost: 0 bytes in 0 blocks
// ==163946==    still reachable: 14 bytes in 2 blocks
// ==163946==         suppressed: 0 bytes in 0 blocks
// ==163946== Rerun with --leak-check=full to see details of leaked memory
// ==163946== 
// ==163946== Use --track-origins=yes to see where uninitialised values come from
// ==163946== For lists of detected and suppressed errors, rerun with: -s
// ==163946== ERROR SUMMARY: 2 errors from 2 contexts (suppressed: 0 from 0)