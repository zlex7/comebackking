var xhrRequest = function (url, type, callback) {
  var xhr = new XMLHttpRequest();
  xhr.onload = function () {
    callback(this.responseText);
  };
  xhr.open(type, url);
  xhr.send();
};

function locationSuccess() {
  // Construct URL
  //long: 30.331013
  //lat: -97.720123
  //TESTING:
  //var url = "http://api.openweathermap.org/data/2.5/weather?lat=30.331013&lon=-97.720123";
  
//   //PRODUCTION:
   var url = "http://pleaseinsult.me/api"; 

  // Send request to OpenWeatherMaphttp://pleaseinsult.me/api?severity=extreme
  xhrRequest(url, 'GET', 
    function(responseText) {
      // responseText contains a JSON object with weather info
      var json = JSON.parse(responseText);

      // Temperature in Kelvin requires adjustment
      var temperature =json.insult;
      console.log("Temperature is " + temperature);

      // Conditions
      var conditions = json.insult;      
      console.log("Conditions are " + conditions);
      
      // Assemble dictionary using our keys
      var dictionary = {
        "KEY_comeback": temperature,
        "KEY_compliments": conditions
      };

      // Send to Pebble
      Pebble.sendAppMessage(dictionary,
        function(e) {
          console.log("new Insult");
        },
        function(e) {
          console.log("Fail insult");
        }
      );
    }      
  );
}

function locationError(err) {
  console.log("Error requesting location!");
}

function getWeather() {
  navigator.geolocation.getCurrentPosition(
    locationSuccess,
    locationError,
    {timeout: 15000, maximumAge: 60000}
  );
}

// Listen for when the watchface is opened
Pebble.addEventListener('ready', 
  function(e) {
    console.log("PebbleKit JS ready!");

    // Get the initial weather
    getWeather();
  }
);

// Listen for when an AppMessage is received
Pebble.addEventListener('appmessage',
  function(e) {
    console.log("AppMessage received!");
    getWeather();
  }                     
);
