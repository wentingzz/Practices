WITH VisitDiff AS (
    SELECT id, visit_date, people,
        id - ROW_NUMBER() OVER (ORDER BY id) AS gap
    FROM Stadium
    WHERE people  >= 100
)

SELECT
    v.id,
    v.visit_date,
    v.people
FROM VisitDiff v
WHERE v.gap IN 
    (SELECT vd.gap 
    FROM VisitDiff vd
    GROUP BY vd.gap
    HAVING COUNT(*) >= 3
    )
ORDER BY v.visit_date;
