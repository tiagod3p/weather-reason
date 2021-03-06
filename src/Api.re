let api =
  "https://api.openweathermap.org/data/2.5/weather?appid=" ++ Env.api_key;
let apiByCity = city => api ++ "&q=" ++ city;
let apiByGeo = (lat, lon) =>
  api
  ++ "&lat="
  ++ Js.Float.toString(lat)
  ++ "&lon="
  ++ Js.Float.toString(lon);

type apiBy =
  | City(string)
  | Geo(float, float);

let getEndpoint = query =>
  switch (query) {
  | City(city) => apiByCity(city)
  | Geo(lat, lon) => apiByGeo(lat, lon)
  };

type weatherData = {
  temp: float,
  location: string,
  description: string,
  icon: string,
};

let formatWeatherData = (w: Decode.response) => {
  temp: w.main.temp,
  location: w.name,
  description: w.weather[0].description,
  icon: w.weather[0].icon,
};

let fetchWeather = endpoint =>
  Js.Promise.(
    Fetch.fetch(endpoint)
    |> then_(Fetch.Response.json)
    |> then_(json =>
         json |> Decode.decodeResponse |> formatWeatherData |> resolve
       )
  );

let getWeather = query => query |> getEndpoint |> fetchWeather;



