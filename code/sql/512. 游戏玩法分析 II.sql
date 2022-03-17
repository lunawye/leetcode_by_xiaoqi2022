# Write your MySQL query statement below
select Activity.player_id,Activity.device_id from Activity  join (select player_id,min(event_date) as e from Activity group by player_id) as a where  Activity.event_date=a.e and Activity.player_id=a.player_id;
