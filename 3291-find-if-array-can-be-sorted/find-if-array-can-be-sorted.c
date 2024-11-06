bool canSortArray(const int *const nums, const uint8_t n) {
    uint16_t pmax = 0, cmin = 0, cmax = 0;
    uint8_t pcnt = 0;
    for (uint8_t i = 0; i < n; i++) {
        const uint16_t v = nums[i];
        const uint8_t ccnt = __builtin_popcount(v);
        if (pcnt == ccnt) {
            cmin = cmin > v ? v : cmin;
            cmax = cmax < v ? v : cmax;
        } else if (cmin < pmax) {
            return false;
        } else {
            pmax = cmax;
            cmin = cmax = v;
            pcnt = ccnt;
        }
    }
    return cmin >= pmax;
}