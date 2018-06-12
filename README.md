Polymer Challenge
Developer: Md Reshad Bin Harun
Date: 12th June, 2018

Design:
Food Show CRM:
Client-side:
* Table object asynchronously loaded every-time a sorting is done or update is invoked
Server-sider:
* SQL database to store in table all fields. On loading client-side HTML, the table is pulled from the database as a JSON object
* Status updates are made using a different API route

Implementation:
1. Server-side:
* install dependencies using node
* set up route "GET" for getting database as JSON
* set up route "POST" for making a status update
* set up route "POST" to add a company

2. Client-side:
* HTML 1:
What would you like to do?
    1. Register company
    2. Check Status
    3. Update Status
    
    TECH STACK USED:
    * NodeJs for server-side
    * SQL for backend
    * HTML/Javascript for front-end
    
    Please refer to comments on the files for documentation
