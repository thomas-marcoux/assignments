(DEFUN INC (L)
  (COND ((NULL L) NIL)
	 (T (CONS (+ 1 (CAR L))(INC (CDR L)))))))
