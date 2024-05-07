SELECT customer_id, COUNT(v.visit_id) as count_no_trans
FROM Visits v
LEFT JOIN Transactions t on v.visit_id = t.visit_id
WHERE transaction_id is null
GROUP BY customer_id