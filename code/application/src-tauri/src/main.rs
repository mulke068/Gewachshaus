// Prevents additional console window on Windows in release, DO NOT REMOVE!!
#![cfg_attr(not(debug_assertions), windows_subsystem = "windows")]


use tauri::{Manager, Menu /* ,CustomMenuItem , MenuItem , Submenu*/};
/*
// Learn more about Tauri commands at https://tauri.app/v1/guides/features/command
#[tauri::command]
async fn close_loadingscreen (window: tauri::Window) {
    if let Some(loadingscreen) = window.get_window("loadingscreen") {
        loadingscreen.close().unwrap();
    }
    window.get_window("main").unwrap().show().unwrap();
}


fn main() {
    tauri::Builder::default()
        .invoke_handler(tauri::generate_handler![close_loadingscreen])
        .run(tauri::generate_context!())
        .expect("Error while running the application");
}
*/

fn main() {
    let menu = Menu::new();
    tauri::Builder::default()
        .setup(|app| {
            let loadingscreen_window = app.get_window("loadingscreen").unwrap();
            let main_window = app.get_window("main").unwrap();
            tauri::async_runtime::spawn(async move {
                println!("Loading...");
                std::thread::sleep(std::time::Duration::from_secs(10));
                println!("Loading done!");

                loadingscreen_window.close().unwrap();
                main_window.show().unwrap();
            });
            Ok(())
        })
        .menu(menu)
        .on_menu_event(|event| {
            match event.menu_item_id() {
                "close" => {
                    event.window().close().unwrap();
                }
                _ => {}
            }
        })
        .run(tauri::generate_context!())
        .expect("Error while running the application");
}