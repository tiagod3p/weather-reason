open Utils;
open Api;

[@react.component]
let make = () => {
  let (weather, setWeather) = React.useState(_ => None);

  React.useEffect0(() => {
    Js.Promise.(
      getWeather(City("sao paulo"))
      |> then_(data => setWeather(_ => Some(data)) |> resolve)
      |> catch(e => {
           Js.log(e);
           setWeather(_ => None) |> resolve;
         })
      |> ignore
    );
    None;
  });

  <div>
    {switch (weather) {
     | Some(data) => <Weather data />
     | None => <h1> {s("Loading...")} </h1>
     }}
  </div>;
};





