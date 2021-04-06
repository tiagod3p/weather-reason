open Utils;
open Api;

[@react.component]
let make = () => {
  let (weather, setWeather) = React.useState(_ => None);

  let onWeather = w =>
    Js.Promise.(
      w
      |> then_(data => setWeather(_ => Some(data)) |> resolve)
      |> catch(e => {
           Js.log(e);
           setWeather(_ => None) |> resolve;
         })
      |> ignore
    );

  let onCity = city => getWeather(City(city)) |> onWeather;

  React.useEffect0(() => {
    let sendGeo = (lat, lon) => getWeather(Geo(lat, lon)) |> onWeather;
    let sendErr = e => Js.log(e);

    Geo.getGeoLocation(~sendGeo, ~sendErr);
    None;
  });

  <div>
    {switch (weather) {
     | Some(data) => <Weather data />
     | None => <h1> {s("Loading...")} </h1>
     }}
    <CityForm onCity />
  </div>;
};







