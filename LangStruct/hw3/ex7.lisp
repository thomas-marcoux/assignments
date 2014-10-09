(DEFUN COPY (S N)
  (COND ((> N 0) (CONS S (COPY S (- N 1))))))
