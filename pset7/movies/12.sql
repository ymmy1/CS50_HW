SELECT title
FROM movies
JOIN stars ON movies.id = stars.movie_id
JOIN people ON stars.person_id = people.id
WHERE name ="Johnny Depp" or name = "Helena Bonham Carter"
group by 1
having count(*) > 1;