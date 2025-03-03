def hasCycle(head)
  return false if head.nil? || head.next.nil?
  
  p = head

  while p && p.next
    head = head.next
    p = p.next.next 

    if head == p
      return true
    end
  end
  return false
end
