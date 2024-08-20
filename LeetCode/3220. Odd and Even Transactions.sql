SELECT tt.transaction_date, 
    SUM(CASE WHEN tt.type = 1 THEN tt.amount ELSE 0 END) as 'odd_sum',
    SUM(CASE WHEN tt.type = 0 THEN tt.amount ELSE 0 END) as 'even_sum'
FROM (
    SELECT t.*, MOD(t.amount, 2) as 'type' 
    FROM transactions t
    ) as tt
GROUP BY tt.transaction_date
ORDER BY tt.transaction_date



# BETTER SOLUTION
SELECT tt.transaction_date, 
    SUM(CASE WHEN MOD(tt.amount, 2) = 1 THEN tt.amount ELSE 0 END) as 'odd_sum',
    SUM(CASE WHEN MOD(tt.amount, 2) = 0 THEN tt.amount ELSE 0 END) as 'even_sum'
FROM transactions tt
GROUP BY tt.transaction_date
ORDER BY tt.transaction_date
