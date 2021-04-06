open Utils;

[@react.component]
let make = (~onCity) => {
  let (value, setValue) = React.useState(_ => "");

  let onSubmit = e => {
    e->ReactEvent.Form.preventDefault;
    onCity(value);
  };

  <form onSubmit className="city-form">
    <input
      type_="text"
      placeholder="Enter city..."
      value
      onChange={e => e->ReactEvent.Form.target##value |> setValue}
    />
    <button type_="submit"> {s("Search Weather")} </button>
  </form>;
};



