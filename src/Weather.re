open Utils;

[@react.component]
let make = (~data: Api.weatherData) => {
  let imgSrc = src => requireImage("./assets/icons/" ++ src ++ ".png");
  let celsiusString: string => string = [%bs.raw
    {|function celsiusString(c) {
    return `${c}°C`
  }|}
  ];

  <div className="weather-card">
    <img src={data.icon |> imgSrc} alt={data.description} />
    <p> {s(data.location)} </p>
    <p> {s(data.description)} </p>
    <p> {data.temp |> ktoC |> Js.Float.toFixed |> celsiusString |> s} </p>
  </div>;
};






