SELECT DISTINCT name
FROM people
JOIN stars ON movies.id = stars.movie_id
JOIN movies ON stars.person_id = people.id
WHERE stars.movie_id IN 
(
SELECT movie_id
FROM stars
JOIN people ON stars.person_id = people.id
WHERE name ="Kevin Bacon" and birth = 1958
) 
and name != "Kevin Bacon"