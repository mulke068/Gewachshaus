// Prevents additional console window on Windows in release, DO NOT REMOVE!!
#![cfg_attr(not(debug_assertions), windows_subsystem = "windows")]


use tauri::{
    Manager, 
    Menu ,
    CustomMenuItem , 
    SystemTrayMenu, 
    SystemTray, 
    SystemTrayEvent, 
    AppHandle};
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
    
    let tray_menu = SystemTrayMenu::new()
        .add_item(CustomMenuItem::new("local", "local"))
        .add_item(CustomMenuItem::new("online", "online"));
    
    let tray = SystemTray::new().with_menu(tray_menu);

    tauri::Builder::default()
        .system_tray(tray)
        .on_system_tray_event(on_system_tray_event)
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

fn on_system_tray_event(
    app: &AppHandle,
    event: SystemTrayEvent,
) {
    match event {
        SystemTrayEvent::MenuItemClick { id, .. } => {
            let id_handle = app.tray_handle().get_item(&id);
            dbg!(&id);
            match id.as_str() {
                "local" => {
                    let local_window = app.get_window("local").unwrap();
                    let online_window = app.get_window("online").unwrap();
                    if local_window.is_visible().unwrap() {
                        local_window.hide().unwrap();
                    } else {
                        online_window.hide().unwrap();
                        local_window.show().unwrap();
                    };
                    id_handle.set_title("local").unwrap();
                },
                "online" => {
                    let local_window = app.get_window("local").unwrap();
                    let online_window = app.get_window("online").unwrap();
                    if online_window.is_visible().unwrap() {
                        online_window.hide().unwrap();
                    } else {
                        local_window.hide().unwrap();
                        online_window.show().unwrap();
                    };
                    id_handle.set_title("online").unwrap();
                }
                _ => {}
            }
        } 
        _ => {}
    }
}