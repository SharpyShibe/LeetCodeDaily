class Solution {
    func findEvenNumbers(_ digits: [Int]) -> [Int] {

    	var freq = [Int](repeating: 0, count: 10)
    	var requiredDigits = [Int](repeating: 0, count: 10)
    	for d in digits {
        	freq[d] += 1
    	}
    
    	var result = [Int]()
    
    	for i in stride(from: 100, through: 998, by: 2) {
        	let centum = i / 100
        	let decem = (i / 10) % 10
        	let unitas = i % 10
        
        	for j in 0..<10 {
            	requiredDigits[j] = 0
        	}
        	requiredDigits[centum] += 1
        	requiredDigits[decem] += 1
        	requiredDigits[unitas] += 1
        
        	var canFormNumber = true
        	for j in 0..<10 {
            	if requiredDigits[j] > freq[j] {
                	canFormNumber = false 
                	break
            	}
        	}
        
        	if canFormNumber {
            		result.append(i)
        	}
    	}
    
    	return result
    }

}
