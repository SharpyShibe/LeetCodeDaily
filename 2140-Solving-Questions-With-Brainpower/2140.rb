# @param {Integer[][]} questions
# @return {Integer}
def most_points(questions) 

  n = questions.size 

  dp = Array.new(n + 1, 0)

  (n - 1).downto(0) do |i|
  
    points, brainpower = questions[i]

    skip = dp[i + 1] 
    solve_index = [i + brainpower + 1, n].min 
    solve = points + dp[solve_index] 

    dp[i] = [skip, solve].max

  end
  dp[0]
end
