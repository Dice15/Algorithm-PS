const solution=(num_list)=>Number(num_list.reduce((gob, e)=>gob*e,1)<Math.pow(num_list.reduce((sum, e)=>sum+e,0), 2));
