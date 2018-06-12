const path = require('path');
var express = require('express');
var app = express();
var bodyParser = require('body-parser');
app.use(bodyParser.urlencoded({extended : true}));
app.listen(process.env.PORT || 3000);

app.get('/', function (req, res) {
  res.sendFile(path.join(__dirname + '/public/index.html'));
});
