func findLucky(arr []int) int {
    count := make([]int, 500)

    for _, num := range arr {
        count[num-1] += 1
    }

    maxLucky := -1
    for i := 0; i<500; i++ {
        if i+1 == count[i] {
            maxLucky = i+1
        }
    }
    return maxLucky;
}
