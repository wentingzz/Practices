/* Better Solution */
SELECT w2.id
FROM Weather w2 
LEFT JOIN Weather w1 ON w1.recordDate = DATEADD(DAY, -1, w2.recordDate)
WHERE w1.temperature < w2.temperature

/* Slow Solution */
SELECT w2.id FROM Weather w1, Weather w2
WHERE w1.temperature < w2.temperature and DATEDIFF(day, w1.recordDate, w2.recordDate) = 1
