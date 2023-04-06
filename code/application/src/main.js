import { invoke } from '@tauri-apps/api/tauri'

const invoke = window.__TAURI__.invoke

/*
document.addEventListener('DOMContentLoaded', () => {
  invoke('close_loadingscreen')

})
*/

document.addEventListener(
    "contextmenu",
    function (event) {
      alert("You've tried to open context menu"); //here you draw your own menu
      event.preventDefault();
      return false;
    },
    { capture: true }
);
