from setuptools import find_packages
from setuptools import setup

setup(
    name='ctrl_interface',
    version='0.0.0',
    packages=find_packages(
        include=('ctrl_interface', 'ctrl_interface.*')),
)
