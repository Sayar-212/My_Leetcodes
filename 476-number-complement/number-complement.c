int findComplement(int num)
{
    int n = num; return ~n & ((num |= (num |= (num |= (num |= (num |= num >> 1) >> 2) >> 4) >> 8) >> 16));
}