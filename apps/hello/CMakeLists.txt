qt_add_executable(hello
    main.cpp
    mainwindow.h
    mainwindow.cpp
)

target_link_libraries(hello PRIVATE Qt6::Widgets)

set_target_properties(hello PROPERTIES
    WIN32_EXECUTABLE ON
    MACOSX_BUNDLE ON
)
