
(cl:in-package :asdf)

(defsystem "robot_msgs-msg"
  :depends-on (:roslisp-msg-protocol :roslisp-utils )
  :components ((:file "_package")
    (:file "UpToDown" :depends-on ("_package_UpToDown"))
    (:file "_package_UpToDown" :depends-on ("_package"))
    (:file "DownToUp" :depends-on ("_package_DownToUp"))
    (:file "_package_DownToUp" :depends-on ("_package"))
  ))