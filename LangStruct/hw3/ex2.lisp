(DEFUN PAIRUP(L)
  (COND ((NULL L) NIL)
	((= (LENGTH L) 1) L)
	(T (CONS (LIST (CAR L) (CADR L))(PAIRUP (CDR (CDR L)))))))
(PAIRUP '(1 2 3 4 5 6))