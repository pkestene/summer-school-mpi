/****************************************************************
 *                                                              *
 * This file has been written as a sample solution to an        *
 * exercise in a course given at the CSCS Summer School.        *
 * It is made freely available with the understanding that      *
 * every copy of this file must include this header and that    *
 * CSCS take no responsibility for the use of the enclosed      *
 * teaching material.                                           *
 *                                                              *
 * Purpose: Exchange ghost cell in 2 directions                 *
 *                                                              *
 * Contents: C-Source                                           *
 *                                                              *
 ****************************************************************/

/* Use only 16 processes for this exercise
 * Send the ghost cell in two directions: left to right and right to left
 *
 * process decomposition on 4*4 grid
 *
 * |-----------|
 * | 0| 1| 2| 3|
 * |-----------|
 * | 4| 5| 6| 7|
 * |-----------|
 * | 8| 9|10|11|
 * |-----------|
 * |12|13|14|15|
 * |-----------|
 *
 * Each process works on a 10*10 (SUBDOMAIN) block of data
 * the D corresponds to data, g corresponds to "ghost cells"
 * gDDDDDDDDDDg
 * gDDDDDDDDDDg
 * gDDDDDDDDDDg
 * gDDDDDDDDDDg
 * gDDDDDDDDDDg
 * gDDDDDDDDDDg
 * gDDDDDDDDDDg
 * gDDDDDDDDDDg
 * gDDDDDDDDDDg
 * gDDDDDDDDDDg
 * gDDDDDDDDDDg
 * gDDDDDDDDDDg
 */

/* Tasks:
 * A. each rank has to find its left and right neighbor
 * B. send them the data they need
 *    - left array goes to left neighbor
 *    - right array goes to right neighbor
 */

#include <stdio.h>
#include <stdlib.h>
#include <mpi.h>

#define SUBDOMAIN 10
#define DOMAINSIZE (SUBDOMAIN+2)

int main(int argc, char *argv[])
{
    int rank, size, i, j, rank_bottom, rank_top;
    double data[DOMAINSIZE*DOMAINSIZE];
    MPI_Request request;
    MPI_Status status;

    MPI_Init(&argc, &argv);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    MPI_Comm_size(MPI_COMM_WORLD, &size);

    if (size!=16) {
        printf("please run this with 16 processors\n");
        MPI_Finalize();
        exit(1);
    }

    for (i=0; i<DOMAINSIZE*DOMAINSIZE; i++) {
        data[i]=rank;
    }

    rank_bottom=// find the rank of bottom neighbor (use schematic to help)!
    rank_top=// find the rank of the top neighbor

    //  ghost cell exchange with the neighbouring cells on the top and on the bottom
    //  a) MPI_Send, MPI_Irecv, MPI_Wait
    //  b) MPI_Isend, MPI_Recv, MPI_Wait
    //  c) MPI_Sendrecv
    //  to the left
    // a)

    // b)

    // c)

    //  to the right
    // a)

    // b)

    // c)


    if (rank==4) {
        printf("data of rank 4 after communication\n");
        for (j=0; j<DOMAINSIZE; j++) {
            for (i=0; i<DOMAINSIZE; i++) {
                printf("%f ", data[i+j*DOMAINSIZE]);
            }
            printf("\n");
        }
    }

    MPI_Finalize();
    return(0);
}