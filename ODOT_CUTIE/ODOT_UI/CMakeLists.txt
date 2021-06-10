cmake_minimum_required (VERSION 3.15)

project(washingMachineUI VERSION 0.0.1 LANGUAGES C CXX ASM)

find_package(Qul)

if (Qul_VERSION VERSION_GREATER_EQUAL "1.7")
    qul_add_target(washingMachineUI)
    set_property(TARGET washingMachineUI APPEND PROPERTY QUL_FONTS_DIR "${CMAKE_CURRENT_SOURCE_DIR}/fonts")
elseif (Qul_VERSION VERSION_EQUAL "1.6")
    add_executable(washingMachineUI)
    set(QUL_FONTS_DIR "${CMAKE_CURRENT_SOURCE_DIR}/fonts,${QUL_FONTS_DIR}")
    target_link_libraries(washingMachineUI
        Qul::QuickUltralite
        Qul::QuickUltralitePlatform)
elseif (Qul_VERSION VERSION_LESS "1.6")
    message(FATAL_ERROR "QUL versions below 1.6 are not supported in this project.")
endif()

file(GLOB_RECURSE imgSources "*.png")
if(imgSources)
    qul_add_resource(washingMachineUI FILES ${imgSources})
endif()

file(GLOB_RECURSE qmlSources "*.qml")
qul_target_qml_sources(washingMachineUI ${qmlSources})

target_link_libraries(washingMachineUI
    Qul::QuickUltraliteTimeline
    Qul::QuickUltraliteControlsStyleDefault)

app_target_setup_os(washingMachineUI)
app_target_default_main(washingMachineUI washingMachineUI)
