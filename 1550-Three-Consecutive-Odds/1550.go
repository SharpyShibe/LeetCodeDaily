func threeConsecutiveOdds(arr []int) bool {
    
    var foundConsec uint8 = 0

    for _, num := range arr {
        if num%2 == 1 {
            foundConsec ++
            if foundConsec == 3 {
                return true
            }
        } else {
            foundConsec = 0
        }
    }
    return false
}
