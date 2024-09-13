# generated from rosidl_generator_py/resource/_idl.py.em
# with input from ctrl_interface:msg/CtrlInterface.idl
# generated code does not contain a copyright notice

# This is being done at the module level and not on the instance level to avoid looking
# for the same variable multiple times on each instance. This variable is not supposed to
# change during runtime so it makes sense to only look for it once.
from os import getenv

ros_python_check_fields = getenv('ROS_PYTHON_CHECK_FIELDS', default='')


# Import statements for member types

import builtins  # noqa: E402, I100

import rosidl_parser.definition  # noqa: E402, I100


class Metaclass_CtrlInterface(type):
    """Metaclass of message 'CtrlInterface'."""

    _CREATE_ROS_MESSAGE = None
    _CONVERT_FROM_PY = None
    _CONVERT_TO_PY = None
    _DESTROY_ROS_MESSAGE = None
    _TYPE_SUPPORT = None

    __constants = {
    }

    @classmethod
    def __import_type_support__(cls):
        try:
            from rosidl_generator_py import import_type_support
            module = import_type_support('ctrl_interface')
        except ImportError:
            import logging
            import traceback
            logger = logging.getLogger(
                'ctrl_interface.msg.CtrlInterface')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._CREATE_ROS_MESSAGE = module.create_ros_message_msg__msg__ctrl_interface
            cls._CONVERT_FROM_PY = module.convert_from_py_msg__msg__ctrl_interface
            cls._CONVERT_TO_PY = module.convert_to_py_msg__msg__ctrl_interface
            cls._TYPE_SUPPORT = module.type_support_msg__msg__ctrl_interface
            cls._DESTROY_ROS_MESSAGE = module.destroy_ros_message_msg__msg__ctrl_interface

    @classmethod
    def __prepare__(cls, name, bases, **kwargs):
        # list constant names here so that they appear in the help text of
        # the message class under "Data and other attributes defined here:"
        # as well as populate each message instance
        return {
        }


class CtrlInterface(metaclass=Metaclass_CtrlInterface):
    """Message class 'CtrlInterface'."""

    __slots__ = [
        '_r_motor',
        '_l_motor',
        '_g_stepper',
        '_s_stepper',
        '_check_fields',
    ]

    _fields_and_field_types = {
        'r_motor': 'int64',
        'l_motor': 'int64',
        'g_stepper': 'int64',
        's_stepper': 'int64',
    }

    # This attribute is used to store an rosidl_parser.definition variable
    # related to the data type of each of the components the message.
    SLOT_TYPES = (
        rosidl_parser.definition.BasicType('int64'),  # noqa: E501
        rosidl_parser.definition.BasicType('int64'),  # noqa: E501
        rosidl_parser.definition.BasicType('int64'),  # noqa: E501
        rosidl_parser.definition.BasicType('int64'),  # noqa: E501
    )

    def __init__(self, **kwargs):
        if 'check_fields' in kwargs:
            self._check_fields = kwargs['check_fields']
        else:
            self._check_fields = ros_python_check_fields == '1'
        if self._check_fields:
            assert all('_' + key in self.__slots__ for key in kwargs.keys()), \
                'Invalid arguments passed to constructor: %s' % \
                ', '.join(sorted(k for k in kwargs.keys() if '_' + k not in self.__slots__))
        self.r_motor = kwargs.get('r_motor', int())
        self.l_motor = kwargs.get('l_motor', int())
        self.g_stepper = kwargs.get('g_stepper', int())
        self.s_stepper = kwargs.get('s_stepper', int())

    def __repr__(self):
        typename = self.__class__.__module__.split('.')
        typename.pop()
        typename.append(self.__class__.__name__)
        args = []
        for s, t in zip(self.get_fields_and_field_types().keys(), self.SLOT_TYPES):
            field = getattr(self, s)
            fieldstr = repr(field)
            # We use Python array type for fields that can be directly stored
            # in them, and "normal" sequences for everything else.  If it is
            # a type that we store in an array, strip off the 'array' portion.
            if (
                isinstance(t, rosidl_parser.definition.AbstractSequence) and
                isinstance(t.value_type, rosidl_parser.definition.BasicType) and
                t.value_type.typename in ['float', 'double', 'int8', 'uint8', 'int16', 'uint16', 'int32', 'uint32', 'int64', 'uint64']
            ):
                if len(field) == 0:
                    fieldstr = '[]'
                else:
                    if self._check_fields:
                        assert fieldstr.startswith('array(')
                    prefix = "array('X', "
                    suffix = ')'
                    fieldstr = fieldstr[len(prefix):-len(suffix)]
            args.append(s + '=' + fieldstr)
        return '%s(%s)' % ('.'.join(typename), ', '.join(args))

    def __eq__(self, other):
        if not isinstance(other, self.__class__):
            return False
        if self.r_motor != other.r_motor:
            return False
        if self.l_motor != other.l_motor:
            return False
        if self.g_stepper != other.g_stepper:
            return False
        if self.s_stepper != other.s_stepper:
            return False
        return True

    @classmethod
    def get_fields_and_field_types(cls):
        from copy import copy
        return copy(cls._fields_and_field_types)

    @builtins.property
    def r_motor(self):
        """Message field 'r_motor'."""
        return self._r_motor

    @r_motor.setter
    def r_motor(self, value):
        if self._check_fields:
            assert \
                isinstance(value, int), \
                "The 'r_motor' field must be of type 'int'"
            assert value >= -9223372036854775808 and value < 9223372036854775808, \
                "The 'r_motor' field must be an integer in [-9223372036854775808, 9223372036854775807]"
        self._r_motor = value

    @builtins.property
    def l_motor(self):
        """Message field 'l_motor'."""
        return self._l_motor

    @l_motor.setter
    def l_motor(self, value):
        if self._check_fields:
            assert \
                isinstance(value, int), \
                "The 'l_motor' field must be of type 'int'"
            assert value >= -9223372036854775808 and value < 9223372036854775808, \
                "The 'l_motor' field must be an integer in [-9223372036854775808, 9223372036854775807]"
        self._l_motor = value

    @builtins.property
    def g_stepper(self):
        """Message field 'g_stepper'."""
        return self._g_stepper

    @g_stepper.setter
    def g_stepper(self, value):
        if self._check_fields:
            assert \
                isinstance(value, int), \
                "The 'g_stepper' field must be of type 'int'"
            assert value >= -9223372036854775808 and value < 9223372036854775808, \
                "The 'g_stepper' field must be an integer in [-9223372036854775808, 9223372036854775807]"
        self._g_stepper = value

    @builtins.property
    def s_stepper(self):
        """Message field 's_stepper'."""
        return self._s_stepper

    @s_stepper.setter
    def s_stepper(self, value):
        if self._check_fields:
            assert \
                isinstance(value, int), \
                "The 's_stepper' field must be of type 'int'"
            assert value >= -9223372036854775808 and value < 9223372036854775808, \
                "The 's_stepper' field must be an integer in [-9223372036854775808, 9223372036854775807]"
        self._s_stepper = value
