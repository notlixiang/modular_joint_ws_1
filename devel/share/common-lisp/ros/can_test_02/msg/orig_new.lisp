; Auto-generated. Do not edit!


(cl:in-package can_test_02-msg)


;//! \htmlinclude orig_new.msg.html

(cl:defclass <orig_new> (roslisp-msg-protocol:ros-message)
  ((ID
    :reader ID
    :initarg :ID
    :type cl:integer
    :initform 0)
   (FUNC
    :reader FUNC
    :initarg :FUNC
    :type cl:integer
    :initform 0)
   (DATA
    :reader DATA
    :initarg :DATA
    :type (cl:vector cl:integer)
   :initform (cl:make-array 8 :element-type 'cl:integer :initial-element 0)))
)

(cl:defclass orig_new (<orig_new>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <orig_new>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'orig_new)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name can_test_02-msg:<orig_new> is deprecated: use can_test_02-msg:orig_new instead.")))

(cl:ensure-generic-function 'ID-val :lambda-list '(m))
(cl:defmethod ID-val ((m <orig_new>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader can_test_02-msg:ID-val is deprecated.  Use can_test_02-msg:ID instead.")
  (ID m))

(cl:ensure-generic-function 'FUNC-val :lambda-list '(m))
(cl:defmethod FUNC-val ((m <orig_new>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader can_test_02-msg:FUNC-val is deprecated.  Use can_test_02-msg:FUNC instead.")
  (FUNC m))

(cl:ensure-generic-function 'DATA-val :lambda-list '(m))
(cl:defmethod DATA-val ((m <orig_new>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader can_test_02-msg:DATA-val is deprecated.  Use can_test_02-msg:DATA instead.")
  (DATA m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <orig_new>) ostream)
  "Serializes a message object of type '<orig_new>"
  (cl:let* ((signed (cl:slot-value msg 'ID)) (unsigned (cl:if (cl:< signed 0) (cl:+ signed 4294967296) signed)))
    (cl:write-byte (cl:ldb (cl:byte 8 0) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) unsigned) ostream)
    )
  (cl:let* ((signed (cl:slot-value msg 'FUNC)) (unsigned (cl:if (cl:< signed 0) (cl:+ signed 4294967296) signed)))
    (cl:write-byte (cl:ldb (cl:byte 8 0) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) unsigned) ostream)
    )
  (cl:map cl:nil #'(cl:lambda (ele) (cl:let* ((signed ele) (unsigned (cl:if (cl:< signed 0) (cl:+ signed 4294967296) signed)))
    (cl:write-byte (cl:ldb (cl:byte 8 0) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) unsigned) ostream)
    ))
   (cl:slot-value msg 'DATA))
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <orig_new>) istream)
  "Deserializes a message object of type '<orig_new>"
    (cl:let ((unsigned 0))
      (cl:setf (cl:ldb (cl:byte 8 0) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) unsigned) (cl:read-byte istream))
      (cl:setf (cl:slot-value msg 'ID) (cl:if (cl:< unsigned 2147483648) unsigned (cl:- unsigned 4294967296))))
    (cl:let ((unsigned 0))
      (cl:setf (cl:ldb (cl:byte 8 0) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) unsigned) (cl:read-byte istream))
      (cl:setf (cl:slot-value msg 'FUNC) (cl:if (cl:< unsigned 2147483648) unsigned (cl:- unsigned 4294967296))))
  (cl:setf (cl:slot-value msg 'DATA) (cl:make-array 8))
  (cl:let ((vals (cl:slot-value msg 'DATA)))
    (cl:dotimes (i 8)
    (cl:let ((unsigned 0))
      (cl:setf (cl:ldb (cl:byte 8 0) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) unsigned) (cl:read-byte istream))
      (cl:setf (cl:aref vals i) (cl:if (cl:< unsigned 2147483648) unsigned (cl:- unsigned 4294967296))))))
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<orig_new>)))
  "Returns string type for a message object of type '<orig_new>"
  "can_test_02/orig_new")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'orig_new)))
  "Returns string type for a message object of type 'orig_new"
  "can_test_02/orig_new")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<orig_new>)))
  "Returns md5sum for a message object of type '<orig_new>"
  "a4978f1551bc91d5aa77344a52f811e5")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'orig_new)))
  "Returns md5sum for a message object of type 'orig_new"
  "a4978f1551bc91d5aa77344a52f811e5")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<orig_new>)))
  "Returns full string definition for message of type '<orig_new>"
  (cl:format cl:nil "int32 ID~%int32 FUNC~%int32[8] DATA~%~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'orig_new)))
  "Returns full string definition for message of type 'orig_new"
  (cl:format cl:nil "int32 ID~%int32 FUNC~%int32[8] DATA~%~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <orig_new>))
  (cl:+ 0
     4
     4
     0 (cl:reduce #'cl:+ (cl:slot-value msg 'DATA) :key #'(cl:lambda (ele) (cl:declare (cl:ignorable ele)) (cl:+ 4)))
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <orig_new>))
  "Converts a ROS message object to a list"
  (cl:list 'orig_new
    (cl:cons ':ID (ID msg))
    (cl:cons ':FUNC (FUNC msg))
    (cl:cons ':DATA (DATA msg))
))
