#include <stdint.h>
#include <stdio.h>
#include <iostream>
#include <string.h>
#include <allegro5/allegro.h>
#include <allegro5/allegro_primitives.h>
#include "imgui.h"
#include "ImGui_SDK_helper.h"
#include <sys/stat.h>
#include <unistd.h>
#include <string>
#include <fstream>
#define MAX_LEN 256

inline bool file_check (const std::string& name) {
  struct stat buffer;
  return (stat (name.c_str(), &buffer) == 0);
}

bool startROS(char *f, char *p)
{
    char buffer[1025] = "";
    snprintf ( buffer, 1025, "roslaunch %s %s", p, f );  
	std::cout << "[DBG] ROS COMMAND buffer: "<< buffer << std::endl;
    bool file_stat = file_check(f);
    int status = system(buffer);
    
    if (!file_stat){
        std::cout << "[DBG] [File Absent] Error: " << strerror(errno) << '\n';
        return false;
    }
    
    else
    {
        if (WIFEXITED(status))
            std::cout << "[DBG] ROS COMMAND SUCCESSFUL, exit code " << WEXITSTATUS(status) << '\n';
        else
            std::cout << "[DBG] ROS COMMAND EXIT abnormal\n";
        return true;
    }
}

int main(int, char**)
{
    al_init();
    al_install_keyboard();
    al_install_mouse();
    al_init_primitives_addon();
    al_set_new_display_flags(ALLEGRO_RESIZABLE);
    ALLEGRO_DISPLAY* display = al_create_display(1280, 720);
    al_set_window_title(display, "ODOT Project");
    ALLEGRO_EVENT_QUEUE* queue = al_create_event_queue();
    al_register_event_source(queue, al_get_display_event_source(display));
    al_register_event_source(queue, al_get_keyboard_event_source());
    al_register_event_source(queue, al_get_mouse_event_source());

    IMGUI_CHECKVERSION();
    ImGui::CreateContext();
    ImGuiIO& io = ImGui::GetIO(); (void)io;
    //io.ConfigFlags |= ImGuiConfigFlags_NavEnableKeyboard;  // Enable Keyboard Controls

    ImGui::StyleColorsDark();

    ImGui_ImplAllegro5_Init(display);

    
    bool show_demo_window = false;
    bool show_another_window = false;
    bool ros_fail = false;
    bool ros_running = false;
    bool ros_bag_needed = false;
    bool ros_bag_started = false;
    ImVec4 clear_color = ImVec4(0.45f, 0.55f, 0.60f, 1.00f);
    char f[MAX_LEN] = "";
    char p[MAX_LEN] = "";
    static int counter = 0;
    char ros_bag_name[MAX_LEN] = "";


    bool running = true;
    while (running)
    {
        ALLEGRO_EVENT ev;
        while (al_get_next_event(queue, &ev))
        {
            ImGui_ImplAllegro5_ProcessEvent(&ev);
            if (ev.type == ALLEGRO_EVENT_DISPLAY_CLOSE)
                running = false;
            if (ev.type == ALLEGRO_EVENT_DISPLAY_RESIZE)
            {
                ImGui_ImplAllegro5_InvalidateDeviceObjects();
                al_acknowledge_resize(display);
                ImGui_ImplAllegro5_CreateDeviceObjects();
            }
        }

        ImGui_ImplAllegro5_NewFrame();
        ImGui::NewFrame();

        char* curr_path;
        bool clrData = false;
        if (show_demo_window)
            ImGui::ShowDemoWindow(&show_demo_window);

        {

            ImGui::Begin("ODOT Project [ROS SENSOR SPAWN]");
            ImGui::Text("Current feature set in this release: Sensor spawning [roslaunch exec.]");             ImGui::Checkbox("Start Data collection (foreground, realtime)", &show_another_window);
            ImGui::InputText("<- ROS Launch File Path", f, MAX_LEN-1);   
            ImGui::InputText("<- ROS Package Name", p, MAX_LEN-1);
            ImGui::Checkbox("Clear collected", &clrData); 
            
	    if (ImGui::Button("Start ROS Sensors")){
                ros_fail = !startROS(f,p);
                ros_running = startROS(f,p);
		ros_bag_needed = false;
	    }
	    
	    if (ImGui::Button("Start ROS Sensors and Bag logs")){
                ros_fail = !startROS(f,p);
                ros_running = startROS(f,p);
		ros_bag_needed = true;
	    }
            ImGui::SameLine();
            ImGui::Text("Current Count = %d", counter);

            ImGui::Text("Application average %.3f ms/frame (%.1f FPS)", 1000.0f / ImGui::GetIO().Framerate, ImGui::GetIO().Framerate);
            ImGui::End();
        }
        if(clrData){
             curr_path = NULL;
            //clearData();
        }
        bool rc = true;
        if (ros_fail)
        {
            ImGui::Begin("FAILED", &ros_fail);
            ImGui::Text("Path or Package name issue, please try again.");
            int bit1 = 2;//readData();
            rc = true;//writeData(); //return true upon write successful
 
            if (ImGui::Button("Ok")){
                ros_fail = false;
            }
            ImGui::End();
        }
        if (ros_running)
        {
            ImGui::Begin("Sensors Spawned and bagging data", &ros_running);
	    if (!ros_bag_started && ros_bag_needed){
	    	system ("cd bags; mv latest/* older/.; cd latest; rosbag record -a &");
	    	ros_bag_started = true;
	    }
            if (ros_bag_started && ros_bag_needed)
            {
                ImGui::Text("Current data is being bagged at: OTU/bags/latest");
                ImGui::Text(
                "Press STOP to stop, enter name and/or path for file below, \n if left unspecified it will be saved in the latest directrory till next bag appears."
                );
            }

            int bit1 = 2;//readData();
            rc = true;//writeData(); //return true upon write successful
            ImGui::InputText("<- ROS Launch File path and/or name", ros_bag_name, MAX_LEN-1);  
            if (ImGui::Button("STOP")){
                if (ros_bag_name != ""){
                    char buffer[MAX_LEN];
                    snprintf ( buffer, 1025, "mv bags/latest/* %s", ros_bag_name);
                    system(buffer);
                }
                system("rosnode kill -a");
                ros_fail = false;
                ros_running = false;
            }
            ImGui::End();
        }
        if (show_another_window)
        {
            ImGui::Begin("Collection Status", &show_another_window);
            
            ImGui::Text("Collecting to ./tmp/");
            
            int bit1 = 2;//readData();
            rc = true;//writeData(); //return true upon write successful
 
            if (ImGui::Button("Ok")){
                show_another_window = false;
            }
            ImGui::End();
        }
                   
        ImGui::Render();
        al_clear_to_color(al_map_rgba_f(clear_color.x * clear_color.w, clear_color.y * clear_color.w, clear_color.z * clear_color.w, clear_color.w));
        ImGui_ImplAllegro5_RenderDrawData(ImGui::GetDrawData());
        al_flip_display();
    }

    ImGui_ImplAllegro5_Shutdown();
    ImGui::DestroyContext();
    al_destroy_event_queue(queue);
    al_destroy_display(display);

    return 0;
}
