from setuptools import find_packages, setup

package_name = 'puckPack'

setup(
    name=package_name,
    version='0.0.0',
    packages=find_packages(exclude=['test']),
    data_files=[
        ('share/ament_index/resource_index/packages',
            ['resource/' + package_name]),
        ('share/' + package_name, ['package.xml']),
    ],
    install_requires=['setuptools'],
    zip_safe=True,
    maintainer='asme',
    maintainer_email='asme@todo.todo',
    description='TODO: Package description',
    license='Apache-2.0',
    tests_require=['pytest'],
    entry_points={
        'console_scripts': [
        'UartCommander = puckPack.UartCommander:main'
        ,
        'controlPC = puckPack.controlPC:main' 
        ,
        'rpiCamera = puckPack.rpiCamera:main'
        ,
        'mainCamera = puckPack.mainCamera:main' 
        ,
        'thinker = puckPack.thinker:main'
        , 
        'choose_color = puckPack.choose_color:main'
        ],
    },
)
