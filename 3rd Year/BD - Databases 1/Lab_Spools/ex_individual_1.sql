accept id_sef char prompt 'Introduceti ecusonul sefului:'
accept data_ang_sef char prompt 'Introduceti data angajarii sefului:'

select nume Nume, data_ang Data_angajare, functie Job, id_sef Ecuson_sef
from angajati1
where id_sef = &id_sef and data_ang > '&data_ang_sef';

undefine id_sef
undefine data_ang_sef