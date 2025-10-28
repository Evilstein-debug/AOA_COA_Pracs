#include <stdio.h>
#include <math.h>

int main() {
    int memoryS, cacheS, blockS, k;

    // Input section
    printf("Enter the size of main memory (in MB): ");
    scanf("%d", &memoryS);

    printf("Enter the size of cache memory (in KB): ");
    scanf("%d", &cacheS);

    printf("Enter the size of Block (in Bytes): ");
    scanf("%d", &blockS);

    printf("Enter the value of K (for K-way set associative): ");
    scanf("%d", &k);

    // 1. Basic calculations

    // Each MB = 2^20 bytes → So total address bits = log2(MB) + 20
    int Mbit = (log2(memoryS) + 20);

    // Word bits (offset within a block)
    int Wbit = log2(blockS);

    // Total number of blocks in main memory
    int no_of_blocks = (memoryS * pow(2, 20)) / blockS;

    // Total number of cache lines
    int no_of_cachelines = (cacheS * pow(2, 10)) / blockS;

    // Cache line bits
    int cachelinebit = log2(no_of_cachelines);

    // Tag bits for direct mapping
    int tag = Mbit - (Wbit + cachelinebit);

    // 2. Display basic details
    printf("\n=== MEMORY AND CACHE DETAILS ===");
    printf("\nTotal number of blocks in Main Memory: %d", no_of_blocks);
    printf("\nTotal number of bits in Main Memory address: %d", Mbit);
    printf("\nTotal number of Cache Lines: %d\n", no_of_cachelines);

    
    // 3. Direct Mapping

    printf("\n=== DIRECT MAPPING ===");
    printf("\nAddress format: [ TAG(%d) ][ LINE(%d) ][ WORD(%d) ]\n", tag, cachelinebit, Wbit);


    // 4. Fully Associative Mapping

    printf("\n=== FULLY ASSOCIATIVE MAPPING ===");
    printf("\nAddress format: [ TAG(%d) ][ WORD(%d) ]\n", (tag + cachelinebit), Wbit);


    // 5. K-Way Set Associative Mapping

    int no_of_sets = no_of_cachelines / k;   // Number of sets = total cache lines / k
    int set_bit = log2(no_of_sets);          // Bits needed to identify a set
    int tag_set = Mbit - (Wbit + set_bit);   // Remaining bits are tag bits

    printf("\n=== %d-WAY SET ASSOCIATIVE MAPPING ===", k);
    printf("\nAddress format: [ TAG(%d) ][ SET(%d) ][ WORD(%d) ]\n", tag_set, set_bit, Wbit);


    // 6. Block placement calculation

    int block_number;
    printf("\nEnter the block number to find its cache location: ");
    scanf("%d", &block_number);

    // Direct Mapping: block number mod total cache lines = cache line number
    int cache_line_number = block_number % no_of_cachelines;
    printf("\nIn Direct Mapping, Block %d will be placed in Cache Line %d.", block_number, cache_line_number);

    // K-way Mapping: block number mod total sets = set number
    int set_number = block_number % no_of_sets;
    printf("\nIn %d-Way Set Associative Mapping, Block %d will be placed in Set %d.\n", k, block_number, set_number);

    // Fully Associative Mapping: block can go anywhere
    printf("\nIn Fully Associative Mapping, Block %d can be placed in ANY Cache Line.\n", block_number);

    printf("\n--- End of Simulation ---\n");

    return 0;
}
