; Auto-generated. Do not edit!


(cl:in-package can_test_02-msg)


;//! \htmlinclude recv.msg.html

(cl:defclass <recv> (roslisp-msg-protocol:ros-message)
  ((ID
    :reader ID
    :initarg :ID
    :type cl:integer
    :initform 0)
   (TYPE
    :reader TYPE
    :initarg :TYPE
    :type cl:string
    :initform "")
   (DATA
    :reader DATA
    :initarg :DATA
    :type cl:integer
    :initform 0))
)

(cl:defclass recv (<recv>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <recv>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'recv)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name can_test_02-msg:<recv> is deprecated: use can_test_02-msg:recv instead.")))

(cl:ensure-generic-function 'ID-val :lambda-list '(m))
(cl:defmethod ID-val ((m <recv>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader can_test_02-msg:ID-val is deprecated.  Use can_test_02-msg:ID instead.")
  (ID m))

(cl:ensure-generic-function 'TYPE-val :lambda-list '(m))
(cl:defmethod TYPE-val ((m <recv>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader can_test_02-msg:TYPE-val is deprecated.  Use can_test_02-msg:TYPE instead.")
  (TYPE m))

(cl:ensure-generic-function 'DATA-val :lambda-list '(m))
(cl:defmethod DATA-val ((m <recv>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader can_test_02-msg:DATA-val is deprecated.  Use can_test_02-msg:DATA instead.")
  (DATA m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <recv>) ostream)
  "Serializes a message object of type '<recv>"
  (cl:let* ((signed (cl:slot-value msg 'ID)) (unsigned (cl:if (cl:< signed 0) (cl:+ signed 4294967296) signed)))
    (cl:write-byte (cl:ldb (cl:byte 8 0) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) unsigned) ostream)
    )
  (cl:let ((__ros_str_len (cl:length (cl:slot-value msg 'TYPE))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) __ros_str_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) __ros_str_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) __ros_str_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) __ros_str_len) ostream))
  (cl:map cl:nil #'(cl:lambda (c) (cl:write-byte (cl:char-code c) ostream)) (cl:slot-value msg 'TYPE))
  (cl:let* ((signed (cl:slot-value msg 'DATA)) (unsigned (cl:if (cl:< signed 0) (cl:+ signed 4294967296) signed)))
    (cl:write-byte (cl:ldb (cl:byte 8 0) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) unsigned) ostream)
    )
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <recv>) istream)
  "Deserializes a message object of type '<recv>"
    (cl:let ((unsigned 0))
      (cl:setf (cl:ldb (cl:byte 8 0) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) unsigned) (cl:read-byte istream))
      (cl:setf (cl:slot-value msg 'ID) (cl:if (cl:< unsigned 2147483648) unsigned (cl:- unsigned 4294967296))))
    (cl:let ((__ros_str_len 0))
      (cl:setf (cl:ldb (cl:byte 8 0) __ros_str_len) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) __ros_str_len) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) __ros_str_len) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) __ros_str_len) (cl:read-byte istream))
      (cl:setf (cl:slot-value msg 'TYPE) (cl:make-string __ros_str_len))
      (cl:dotimes (__ros_str_idx __ros_str_len msg)
        (cl:setf (cl:char (cl:slot-value msg 'TYPE) __ros_str_idx) (cl:code-char (cl:read-byte istream)))))
    (cl:let ((unsigned 0))
      (cl:setf (cl:ldb (cl:byte 8 0) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) unsigned) (cl:read-byte istream))
      (cl:setf (cl:slot-value msg 'DATA) (cl:if (cl:< unsigned 2147483648) unsigned (cl:- unsigned 4294967296))))
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<recv>)))
  "Returns string type for a message object of type '<recv>"
  "can_test_02/recv")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'recv)))
  "Returns string type for a message object of type 'recv"
  "can_test_02/recv")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<recv>)))
  "Returns md5sum for a message object of type '<recv>"
  "b1eccce7bb73e08b7b481de070e7c762")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'recv)))
  "Returns md5sum for a message object of type 'recv"
  "b1eccce7bb73e08b7b481de070e7c762")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<recv>)))
  "Returns full string definition for message of type '<recv>"
  (cl:format cl:nil "int32 ID~%string TYPE~%int32 DATA~%~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'recv)))
  "Returns full string definition for message of type 'recv"
  (cl:format cl:nil "int32 ID~%string TYPE~%int32 DATA~%~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <recv>))
  (cl:+ 0
     4
     4 (cl:length (cl:slot-value msg 'TYPE))
     4
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <recv>))
  "Converts a ROS message object to a list"
  (cl:list 'recv
    (cl:cons ':ID (ID msg))
    (cl:cons ':TYPE (TYPE msg))
    (cl:cons ':DATA (DATA msg))
))
