const path = require('path');
const { Client } = require('pg');
var express = require('express');
var app = express();
var bodyParser = require('body-parser');
app.use(bodyParser.urlencoded({extended : true}));
app.listen(process.env.PORT || 3000);

//setting database connection
DATABASE_URL = config.env.db;
const client = new Client({
connectionString: DATABASE_URL,
ssl: true,
});
client.connect();



app.get('/', function (req, res) {
  res.sendFile(path.join(__dirname + '/public/index.html'));
});

//return all companies in database as JSON object to be parsed on client-side
app.get('/status', function (req, res) {
	var query_string = 'SELECT * FROM CRM';
	console.log(query_string);
	client.query(query_string, (err, res2) => {
	 	if (err) throw err;
	  	res.send(res2);
	  	});
});

//API to update the status of a particular company
app.post('/update', function (req, res) {
	var status = req.body.status;
	var company = req.body.company;
	var query = 'UPDATE CRM SET status=\''+status+'\' WHERE company=\''+company+'\';';
	client.query(query_string, (err, res2) => {
	 	if (err) throw err;
	  	res.send("Status update successful!");
	});
});

//API to register a company
app.post('/register', function (req, res) {
	var status = req.body.status;
	var company = req.body.company;
	var email = req.body.email;
	var name = req.body.name;
	var query = 'insert into CRM (name, company, email, status) values ('+ name +', '+company+', '+email+', '+status+');'
	client.query(query_string, (err, res2) => {
	 	if (err) throw err;
	  	res.send("Registration Successful!");
	});
});
