cmake_minimum_required(VERSION 3.0.2)
project(node_example)

find_package(catkin REQUIRED COMPONENTS dynamic_reconfigure message_generation roscpp roslaunch rosgraph_msgs rospy std_msgs)

add_message_files(
  FILES
  ExampleData.msg
)

generate_messages(
  DEPENDENCIES
  std_msgs
)

generate_dynamic_reconfigure_options(
  cfg/nodeExample.cfg
)

catkin_package(
  CATKIN_DEPENDS dynamic_reconfigure message_runtime roscpp rosgraph_msgs rospy std_msgs
)

include_directories(include ${catkin_INCLUDE_DIRS})

roslaunch_add_file_check(launch)

add_executable(${PROJECT_NAME}_talker src/nodes/talker_node.cpp src/talker.cpp)
target_link_libraries(${PROJECT_NAME}_talker ${catkin_LIBRARIES})
add_dependencies(${PROJECT_NAME}_talker node_example_gencfg node_example_generate_messages_cpp)

add_executable(${PROJECT_NAME}_listener src/listener.cpp src/nodes/listener_node.cpp)
target_link_libraries(${PROJECT_NAME}_listener ${catkin_LIBRARIES})
add_dependencies(${PROJECT_NAME}_listener node_example_gencfg node_example_generate_messages_cpp)

if(CATKIN_ENABLE_TESTING)
  find_package(rostest REQUIRED)

  add_rostest_gtest(test_node_example_talker test/test_node_example_talker.test test/test_node_example_talker.cpp)
  target_link_libraries(test_node_example_talker ${catkin_LIBRARIES})
  add_dependencies(test_node_example_talker node_example_generate_messages_cpp)

  add_rostest_gtest(test_node_example_listener test/test_node_example_listener.test test/test_node_example_listener.cpp)
  target_link_libraries(test_node_example_listener ${catkin_LIBRARIES})
  add_dependencies(test_node_example_listener node_example_generate_messages_cpp)
endif()


install(DIRECTORY include/${PROJECT_NAME}/
  DESTINATION ${CATKIN_PACKAGE_INCLUDE_DESTINATION}
  FILES_MATCHING PATTERN "*.h"
)

# catkin_install_python(PROGRAMS src/pylistener.py src/pytalker.py DESTINATION ${CATKIN_PACKAGE_BIN_DESTINATION})

install(TARGETS node_example_listener node_example_talker
  RUNTIME DESTINATION ${CATKIN_PACKAGE_BIN_DESTINATION}
  LIBRARY DESTINATION ${CATKIN_PACKAGE_LIB_DESTINATION}
  ARCHIVE DESTINATION ${CATKIN_PACKAGE_LIB_DESTINATION}
)

install(DIRECTORY launch
  DESTINATION ${CATKIN_PACKAGE_SHARE_DESTINATION}
)