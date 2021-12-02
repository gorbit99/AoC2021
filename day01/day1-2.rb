p STDIN.each_line.map(&:to_i).each_cons(3).map(&:sum).each_cons(2).filter{|x, y| y > x}.length
