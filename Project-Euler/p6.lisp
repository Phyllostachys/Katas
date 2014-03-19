(defun sum-diff (n)
  (let ((a 0) (b 0))
    (setf a (/ (* (+ n 1) n) 2))
    (setf a (* a a))
    (setf b (/ (* (+ n 1) (+ 1 (* 2 n)) n) 6))
    (- a b)))

(sum-diff 100)