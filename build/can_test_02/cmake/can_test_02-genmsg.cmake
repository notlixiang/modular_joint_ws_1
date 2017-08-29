# generated from genmsg/cmake/pkg-genmsg.cmake.em

message(STATUS "can_test_02: 5 messages, 1 services")

set(MSG_I_FLAGS "-Ican_test_02:/home/null/ros_ws/modular_joint_ws_1/src/can_test_02/msg;-Istd_msgs:/opt/ros/indigo/share/std_msgs/cmake/../msg")

# Find all generators
find_package(gencpp REQUIRED)
find_package(genlisp REQUIRED)
find_package(genpy REQUIRED)

add_custom_target(can_test_02_generate_messages ALL)

# verify that message/service dependencies have not changed since configure



get_filename_component(_filename "/home/null/ros_ws/modular_joint_ws_1/src/can_test_02/msg/recv.msg" NAME_WE)
add_custom_target(_can_test_02_generate_messages_check_deps_${_filename}
  COMMAND ${CATKIN_ENV} ${PYTHON_EXECUTABLE} ${GENMSG_CHECK_DEPS_SCRIPT} "can_test_02" "/home/null/ros_ws/modular_joint_ws_1/src/can_test_02/msg/recv.msg" ""
)

get_filename_component(_filename "/home/null/ros_ws/modular_joint_ws_1/src/can_test_02/msg/orig.msg" NAME_WE)
add_custom_target(_can_test_02_generate_messages_check_deps_${_filename}
  COMMAND ${CATKIN_ENV} ${PYTHON_EXECUTABLE} ${GENMSG_CHECK_DEPS_SCRIPT} "can_test_02" "/home/null/ros_ws/modular_joint_ws_1/src/can_test_02/msg/orig.msg" ""
)

get_filename_component(_filename "/home/null/ros_ws/modular_joint_ws_1/src/can_test_02/msg/DownToUp.msg" NAME_WE)
add_custom_target(_can_test_02_generate_messages_check_deps_${_filename}
  COMMAND ${CATKIN_ENV} ${PYTHON_EXECUTABLE} ${GENMSG_CHECK_DEPS_SCRIPT} "can_test_02" "/home/null/ros_ws/modular_joint_ws_1/src/can_test_02/msg/DownToUp.msg" ""
)

get_filename_component(_filename "/home/null/ros_ws/modular_joint_ws_1/src/can_test_02/msg/orig_new.msg" NAME_WE)
add_custom_target(_can_test_02_generate_messages_check_deps_${_filename}
  COMMAND ${CATKIN_ENV} ${PYTHON_EXECUTABLE} ${GENMSG_CHECK_DEPS_SCRIPT} "can_test_02" "/home/null/ros_ws/modular_joint_ws_1/src/can_test_02/msg/orig_new.msg" ""
)

get_filename_component(_filename "/home/null/ros_ws/modular_joint_ws_1/src/can_test_02/srv/AddTwoInts.srv" NAME_WE)
add_custom_target(_can_test_02_generate_messages_check_deps_${_filename}
  COMMAND ${CATKIN_ENV} ${PYTHON_EXECUTABLE} ${GENMSG_CHECK_DEPS_SCRIPT} "can_test_02" "/home/null/ros_ws/modular_joint_ws_1/src/can_test_02/srv/AddTwoInts.srv" ""
)

get_filename_component(_filename "/home/null/ros_ws/modular_joint_ws_1/src/can_test_02/msg/UpToDown.msg" NAME_WE)
add_custom_target(_can_test_02_generate_messages_check_deps_${_filename}
  COMMAND ${CATKIN_ENV} ${PYTHON_EXECUTABLE} ${GENMSG_CHECK_DEPS_SCRIPT} "can_test_02" "/home/null/ros_ws/modular_joint_ws_1/src/can_test_02/msg/UpToDown.msg" ""
)

#
#  langs = gencpp;genlisp;genpy
#

### Section generating for lang: gencpp
### Generating Messages
_generate_msg_cpp(can_test_02
  "/home/null/ros_ws/modular_joint_ws_1/src/can_test_02/msg/recv.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/can_test_02
)
_generate_msg_cpp(can_test_02
  "/home/null/ros_ws/modular_joint_ws_1/src/can_test_02/msg/orig_new.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/can_test_02
)
_generate_msg_cpp(can_test_02
  "/home/null/ros_ws/modular_joint_ws_1/src/can_test_02/msg/DownToUp.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/can_test_02
)
_generate_msg_cpp(can_test_02
  "/home/null/ros_ws/modular_joint_ws_1/src/can_test_02/msg/orig.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/can_test_02
)
_generate_msg_cpp(can_test_02
  "/home/null/ros_ws/modular_joint_ws_1/src/can_test_02/msg/UpToDown.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/can_test_02
)

### Generating Services
_generate_srv_cpp(can_test_02
  "/home/null/ros_ws/modular_joint_ws_1/src/can_test_02/srv/AddTwoInts.srv"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/can_test_02
)

### Generating Module File
_generate_module_cpp(can_test_02
  ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/can_test_02
  "${ALL_GEN_OUTPUT_FILES_cpp}"
)

add_custom_target(can_test_02_generate_messages_cpp
  DEPENDS ${ALL_GEN_OUTPUT_FILES_cpp}
)
add_dependencies(can_test_02_generate_messages can_test_02_generate_messages_cpp)

# add dependencies to all check dependencies targets
get_filename_component(_filename "/home/null/ros_ws/modular_joint_ws_1/src/can_test_02/msg/recv.msg" NAME_WE)
add_dependencies(can_test_02_generate_messages_cpp _can_test_02_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/null/ros_ws/modular_joint_ws_1/src/can_test_02/msg/orig.msg" NAME_WE)
add_dependencies(can_test_02_generate_messages_cpp _can_test_02_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/null/ros_ws/modular_joint_ws_1/src/can_test_02/msg/DownToUp.msg" NAME_WE)
add_dependencies(can_test_02_generate_messages_cpp _can_test_02_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/null/ros_ws/modular_joint_ws_1/src/can_test_02/msg/orig_new.msg" NAME_WE)
add_dependencies(can_test_02_generate_messages_cpp _can_test_02_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/null/ros_ws/modular_joint_ws_1/src/can_test_02/srv/AddTwoInts.srv" NAME_WE)
add_dependencies(can_test_02_generate_messages_cpp _can_test_02_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/null/ros_ws/modular_joint_ws_1/src/can_test_02/msg/UpToDown.msg" NAME_WE)
add_dependencies(can_test_02_generate_messages_cpp _can_test_02_generate_messages_check_deps_${_filename})

# target for backward compatibility
add_custom_target(can_test_02_gencpp)
add_dependencies(can_test_02_gencpp can_test_02_generate_messages_cpp)

# register target for catkin_package(EXPORTED_TARGETS)
list(APPEND ${PROJECT_NAME}_EXPORTED_TARGETS can_test_02_generate_messages_cpp)

### Section generating for lang: genlisp
### Generating Messages
_generate_msg_lisp(can_test_02
  "/home/null/ros_ws/modular_joint_ws_1/src/can_test_02/msg/recv.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/can_test_02
)
_generate_msg_lisp(can_test_02
  "/home/null/ros_ws/modular_joint_ws_1/src/can_test_02/msg/orig_new.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/can_test_02
)
_generate_msg_lisp(can_test_02
  "/home/null/ros_ws/modular_joint_ws_1/src/can_test_02/msg/DownToUp.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/can_test_02
)
_generate_msg_lisp(can_test_02
  "/home/null/ros_ws/modular_joint_ws_1/src/can_test_02/msg/orig.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/can_test_02
)
_generate_msg_lisp(can_test_02
  "/home/null/ros_ws/modular_joint_ws_1/src/can_test_02/msg/UpToDown.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/can_test_02
)

### Generating Services
_generate_srv_lisp(can_test_02
  "/home/null/ros_ws/modular_joint_ws_1/src/can_test_02/srv/AddTwoInts.srv"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/can_test_02
)

### Generating Module File
_generate_module_lisp(can_test_02
  ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/can_test_02
  "${ALL_GEN_OUTPUT_FILES_lisp}"
)

add_custom_target(can_test_02_generate_messages_lisp
  DEPENDS ${ALL_GEN_OUTPUT_FILES_lisp}
)
add_dependencies(can_test_02_generate_messages can_test_02_generate_messages_lisp)

# add dependencies to all check dependencies targets
get_filename_component(_filename "/home/null/ros_ws/modular_joint_ws_1/src/can_test_02/msg/recv.msg" NAME_WE)
add_dependencies(can_test_02_generate_messages_lisp _can_test_02_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/null/ros_ws/modular_joint_ws_1/src/can_test_02/msg/orig.msg" NAME_WE)
add_dependencies(can_test_02_generate_messages_lisp _can_test_02_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/null/ros_ws/modular_joint_ws_1/src/can_test_02/msg/DownToUp.msg" NAME_WE)
add_dependencies(can_test_02_generate_messages_lisp _can_test_02_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/null/ros_ws/modular_joint_ws_1/src/can_test_02/msg/orig_new.msg" NAME_WE)
add_dependencies(can_test_02_generate_messages_lisp _can_test_02_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/null/ros_ws/modular_joint_ws_1/src/can_test_02/srv/AddTwoInts.srv" NAME_WE)
add_dependencies(can_test_02_generate_messages_lisp _can_test_02_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/null/ros_ws/modular_joint_ws_1/src/can_test_02/msg/UpToDown.msg" NAME_WE)
add_dependencies(can_test_02_generate_messages_lisp _can_test_02_generate_messages_check_deps_${_filename})

# target for backward compatibility
add_custom_target(can_test_02_genlisp)
add_dependencies(can_test_02_genlisp can_test_02_generate_messages_lisp)

# register target for catkin_package(EXPORTED_TARGETS)
list(APPEND ${PROJECT_NAME}_EXPORTED_TARGETS can_test_02_generate_messages_lisp)

### Section generating for lang: genpy
### Generating Messages
_generate_msg_py(can_test_02
  "/home/null/ros_ws/modular_joint_ws_1/src/can_test_02/msg/recv.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/can_test_02
)
_generate_msg_py(can_test_02
  "/home/null/ros_ws/modular_joint_ws_1/src/can_test_02/msg/orig_new.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/can_test_02
)
_generate_msg_py(can_test_02
  "/home/null/ros_ws/modular_joint_ws_1/src/can_test_02/msg/DownToUp.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/can_test_02
)
_generate_msg_py(can_test_02
  "/home/null/ros_ws/modular_joint_ws_1/src/can_test_02/msg/orig.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/can_test_02
)
_generate_msg_py(can_test_02
  "/home/null/ros_ws/modular_joint_ws_1/src/can_test_02/msg/UpToDown.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/can_test_02
)

### Generating Services
_generate_srv_py(can_test_02
  "/home/null/ros_ws/modular_joint_ws_1/src/can_test_02/srv/AddTwoInts.srv"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/can_test_02
)

### Generating Module File
_generate_module_py(can_test_02
  ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/can_test_02
  "${ALL_GEN_OUTPUT_FILES_py}"
)

add_custom_target(can_test_02_generate_messages_py
  DEPENDS ${ALL_GEN_OUTPUT_FILES_py}
)
add_dependencies(can_test_02_generate_messages can_test_02_generate_messages_py)

# add dependencies to all check dependencies targets
get_filename_component(_filename "/home/null/ros_ws/modular_joint_ws_1/src/can_test_02/msg/recv.msg" NAME_WE)
add_dependencies(can_test_02_generate_messages_py _can_test_02_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/null/ros_ws/modular_joint_ws_1/src/can_test_02/msg/orig.msg" NAME_WE)
add_dependencies(can_test_02_generate_messages_py _can_test_02_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/null/ros_ws/modular_joint_ws_1/src/can_test_02/msg/DownToUp.msg" NAME_WE)
add_dependencies(can_test_02_generate_messages_py _can_test_02_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/null/ros_ws/modular_joint_ws_1/src/can_test_02/msg/orig_new.msg" NAME_WE)
add_dependencies(can_test_02_generate_messages_py _can_test_02_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/null/ros_ws/modular_joint_ws_1/src/can_test_02/srv/AddTwoInts.srv" NAME_WE)
add_dependencies(can_test_02_generate_messages_py _can_test_02_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/null/ros_ws/modular_joint_ws_1/src/can_test_02/msg/UpToDown.msg" NAME_WE)
add_dependencies(can_test_02_generate_messages_py _can_test_02_generate_messages_check_deps_${_filename})

# target for backward compatibility
add_custom_target(can_test_02_genpy)
add_dependencies(can_test_02_genpy can_test_02_generate_messages_py)

# register target for catkin_package(EXPORTED_TARGETS)
list(APPEND ${PROJECT_NAME}_EXPORTED_TARGETS can_test_02_generate_messages_py)



if(gencpp_INSTALL_DIR AND EXISTS ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/can_test_02)
  # install generated code
  install(
    DIRECTORY ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/can_test_02
    DESTINATION ${gencpp_INSTALL_DIR}
  )
endif()
if(TARGET std_msgs_generate_messages_cpp)
  add_dependencies(can_test_02_generate_messages_cpp std_msgs_generate_messages_cpp)
endif()

if(genlisp_INSTALL_DIR AND EXISTS ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/can_test_02)
  # install generated code
  install(
    DIRECTORY ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/can_test_02
    DESTINATION ${genlisp_INSTALL_DIR}
  )
endif()
if(TARGET std_msgs_generate_messages_lisp)
  add_dependencies(can_test_02_generate_messages_lisp std_msgs_generate_messages_lisp)
endif()

if(genpy_INSTALL_DIR AND EXISTS ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/can_test_02)
  install(CODE "execute_process(COMMAND \"/usr/bin/python\" -m compileall \"${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/can_test_02\")")
  # install generated code
  install(
    DIRECTORY ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/can_test_02
    DESTINATION ${genpy_INSTALL_DIR}
  )
endif()
if(TARGET std_msgs_generate_messages_py)
  add_dependencies(can_test_02_generate_messages_py std_msgs_generate_messages_py)
endif()
